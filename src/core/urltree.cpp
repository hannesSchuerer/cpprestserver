#include "urltree.h"

#include "utils.h"

namespace shan
{
//------------------------------------------------------------------------------
UrlTree::UrlTree()
{
}
//------------------------------------------------------------------------------
void UrlTree::Insert(const utility::string_t &path, const HandlerFunc &function)
{
    std::vector<utility::string_t> pathSegments = web::uri::split_path(path);
    utility::string_t tmpPath = path;

    if (pathSegments.empty() || path.find('/') == std::string::npos)
    {
        m_function = function;
        return;
    }

    UrlTree *pTmpUrlTree;

    utils::RemoveFirstPathSegment(tmpPath);

    if (m_treeData.find(pathSegments[0]) == m_treeData.end())
    {
        pTmpUrlTree = new UrlTree();
        m_treeData[pathSegments[0]].reset(pTmpUrlTree);
        pTmpUrlTree->Insert(tmpPath, function);
    }
    else
    {
        m_treeData[pathSegments[0]]->Insert(tmpPath, function);
    }
}
//------------------------------------------------------------------------------
HandlerFunc &UrlTree::Find(const utility::string_t &path)
{
    std::vector<utility::string_t> pathSegments = web::uri::split_path(path);
    utility::string_t tmpPath = path;

    if (pathSegments.empty() || path.find('/') == std::string::npos)
        return m_function;

    if (m_treeData.find(pathSegments[0]) == m_treeData.end())
        return m_function;


    utils::RemoveFirstPathSegment(tmpPath);

    return m_treeData[pathSegments[0]]->Find(tmpPath);
}
//------------------------------------------------------------------------------
}
