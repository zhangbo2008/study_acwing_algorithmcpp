#=====acwing:830
print(1)
tmp=[3 ,4 ,2, 7, 5]
res=[]
st=[]
for i in tmp:
    #维护
    while len(st)>0 and st[-1]>=i:
        st.pop()
    
    if st==[]:
        res.append(-1)
        
    else:
        res.append(st[-1])


    #往st添加.

    st.append(i)
print(res)
        
