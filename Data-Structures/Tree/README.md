# Tree

Tree is a non-linear data structure in which the elements are stored in hierarchy structure 

## Terminology
1. Root <br>
    The node which does not have an incoming edge
2. Parent <br>
    The node which has outgoing edges
3. Child <br>
    The node which has incoming edge
4. Level of a node<br> The number of nodes between root and the node
5. Height of a node <br> The number of edges between the root and the node
6. Internal Nodes - Non-leaf nodes
7. External Nodes - Leaf nodes
8. Forest - Group of Trees



## Analysis

- Catalan Number - The number of different Binary trees that can be generated from n (number of nodes)
  
    
    _Labelled Nodes: T(n) = 2nCn/n+1<br>
    Unlabelled Nodes: T(n) = (2nCn/n+1)*n!_
    
- Height vs Nodes
  - For Binary trees
    - If height h is given,
        
        _Minimum number of nodes n = h+1<br> 
        Maximum number of nodes n = <img src="https://latex.codecogs.com/gif.latex?\fn_jvn&space;2^{h&plus;1}" height=15 align=center>_
    
    - If nodes n is given,
  
        _Minimum number of nodes h = n-1<br> 
        Maximum number of nodes h = <img src="https://latex.codecogs.com/gif.latex?\fn_jvn&space;\log_{2}(n&plus;1)-1" height=15 align=center>_
        
  - For Strict m-ary trees<br>
    - If height h is given,

        _Minimum number of nodes n = mh+1<br>
        Maximum number of nodes n = <img src="https://latex.codecogs.com/gif.latex?\fn_jvn&space;m^{h&plus;1}-1/m-1" height=15 align=center>_

    - If nodes n is given,

        _Minimum height h = <img src="https://latex.codecogs.com/gif.latex?\fn_jvn&space;\log_{m}[n(m-1)&plus;1]-1" height=15 align=center><br>
        Maximum height h = n-1/m_