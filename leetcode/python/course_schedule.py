class Vertex(object):
    def __init__(self):
        self.adj = []
        self.d = self.f = None

t = 1


def dfs(u):
    global t
    u.d = t
    t += 1
    for v in u.adj:
        if v.d is None:
            if not dfs(v):
                return False
        elif v.f is None:
            return False
    u.f = t
    t += 1
    return True


class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = [Vertex() for i in xrange(numCourses)]
        for x, y in prerequisites:
            graph[x].has_pre = True
            graph[y].adj.append(graph[x])
        for u in graph:
            if u.d is None:
                if not dfs(u):
                    return False
        return True

if __name__ == '__main__':
    sol = Solution()
    print sol.canFinish(4, [[0,1],[1,0]])