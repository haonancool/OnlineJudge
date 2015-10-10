class Vertex(object):
    def __init__(self):
        self.adj = []
        self.state = 0


def dfs(u, graph, ret):
    graph[u].state = 1
    for v in graph[u].adj:
        if graph[v].state == 0:
            if not dfs(v, graph, ret):
                return False
        elif graph[v].state == 1:
            return False
    graph[u].state = 2
    ret.append(u)
    return True


class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        graph = [Vertex() for i in xrange(numCourses)]
        for x, y in prerequisites:
            graph[y].adj.append(x)
        ret = []
        for u in xrange(numCourses):
            if graph[u].state == 0:
                if not dfs(u, graph, ret):
                    return []
        ret.reverse()
        return ret
