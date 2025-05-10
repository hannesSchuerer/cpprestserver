#include "restregistrator.h"

#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>

#include "log.h"
#include "urltree.h"
#include "utils.h"

namespace shan
{
//------------------------------------------------------------------------------
RestRegistrator &RestRegistrator::GetInstance()
{
    static RestRegistrator restRegistrator;
    return restRegistrator;
}
//------------------------------------------------------------------------------
void RestRegistrator::Register(const std::string &path,
                               const std::string &method,
                               const HandlerFunc &handler)
{
    if (m_treeData.find(method) == m_treeData.end())
    {
        UrlTree *pTmpUrlTree = new UrlTree();
        m_treeData[method].reset(pTmpUrlTree);
        pTmpUrlTree->Insert(utility::conversions::to_string_t(path), handler);
    }

    m_treeData[method]->Insert(utility::conversions::to_string_t(path),
                               handler);
}
//------------------------------------------------------------------------------
HandlerFunc &RestRegistrator::GetHandler(const std::string &path,
                                         const std::string &method)
{
    m_currentHandler = 0;

    if (m_treeData.find(method) == m_treeData.end())
        return m_currentHandler;

    m_currentHandler =
        m_treeData[method]->Find(utility::conversions::to_string_t(path));

    return m_currentHandler;
}
//------------------------------------------------------------------------------
}
