n=7
storedfs=[]
adj=[[],[2], [1,4], [5], [2, 6], [3], [4,7], [2,6]]
vis=[False for i in range(n+1)]
def dfs(node):
    storedfs.append(node)
    vis[node]=True
    for k in adj[node]:
        if vis[k]==False:
            dfs(k)

for i in range(1,len(vis)):
    if vis[i]==False:
        dfs(i)
   
print(storedfs)
