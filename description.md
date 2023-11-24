# **Limit**
## Time : 2 sec
## Memory : 64 MB

Tahsin loves graph theory very much. He is especially fond of trees. For his upcoming birthday his friends decided to gift him a tree, lets call it birthday tree. Birthday tree consists of *n* node numbered *1* to *n*, having a light in every node. Initially some of the light is turned on and some are turned off. 

Root of the tree is *1*. The tree has a special property, when a node is toggled, all the children of the node is also toggled. So if you toggle the node *i*, you also toggle the children of *i* and so on. 

In order to help Tahsin understand the tree better, you are going help him process *q* queries.

# **Input**

Input starts with *T (1 <= T <= 5)*.

The first line of every test containers two integers *$n (1 <= n <= 10^5)$* and *$q (1 <= q <= 10^5)$*, denoting the number of nodes in the tree and the number of queries respectively.

The next line contains n integers, *$a_1..a_n$*, where *$a_i = 1$*, if the light in node *i* is turned on, and *$a_i = 0$*, if the light in node *i* is turned off.

Each of the next *n - 1* lines contains two integers *u* and *v* *(1 <= u, v <= n)*, denoting there is an edge between *u* and *v*.

The next q lines contains a single integer *$q_i (1 <= q_i <= n)$*, denoting the node to be toggled.

# **Output**

For each case, after processing all the queries, print *n* integers, *$b_1..b_n$*, denoting the status of the node.

See the sample test case for input output format.