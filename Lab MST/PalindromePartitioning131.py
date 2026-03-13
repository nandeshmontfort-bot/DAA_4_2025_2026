class Solution(object):
    def partition(self, s):
        self.a = []
        self.dfs(s, [])
        return self.a
    def dfs(self,s,path):
        if not s :
            self.a.append(path)
            return
        for i in range(1,len(s)+1):
            if s[:i] == s[:i][::-1]:
                self.dfs(s[i:],path + [s[:i]])
