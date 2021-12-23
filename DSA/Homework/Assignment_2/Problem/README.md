1) bstsort function:
    inorder traversal of the bst prints the elements in ascending order.
    Time complexity is O(n).

2) finddepth function:
    we call the finddepth_2 func. This then returns the depth of the given node for a general binary tree.
    Use of recursion and the time complexity is O(n).

3) Height function:
    Calls the height_2 func. We then find the height of both the left and right subtrees and then return height = Max(left,right) + 1 -->(for the root).
    Use of recursion and time complexity = O(n).

4) isbst function:
    we call the isbst_2 func. then check if the conditions of a bst are satisfied for all the nodes of left and right subtrees.
    Use of max_value and min_value functions. If yes, print 1; else return 0. Complexity = O(n).

**PROBLEM 5**:
    we generate a random bst and then calculate avg heights for various values of m. Print a 2D array in a separate file.

    --> From the 3D graph generated, we figure out that the avgDepth is dependent on k(log(n)), where n is the number of nodes of the bst and k is a constant.

6) inRange:
    We again perform the inorder traversal of the bst and print the number only if lies inside the range of k1,k2. This
    way we are able to print the numbers in ascending order.
    

