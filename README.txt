Part a) My selection sort is stable because in the inner for loop, values are
        being compared with the "<" operator and not the "<=" operator.
        Therefore, if two values are equal, their relative positions in the list
        will not change once the sorting is complete because the swapping part
        will swap the value with itself (which doesn't move it at all).
