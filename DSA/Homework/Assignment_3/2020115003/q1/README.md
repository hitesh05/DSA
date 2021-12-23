The range of even integers has been restricted to 1500 so that we get more collisons, which makes our analysis easier.
The values considered are mentioned in the "out.txt" file in the "analysis/q1_analysis" directory.

<Probing Analysis>
We are running the code 5 times.

Separate Chaining:
The average probes are always 1 because we insert the key in a linked list after hashing. Hence we don't have
to look for empty indices inside the hash table itself. Howerver, this method for resolving collisions can be time consuming for large inputs.

Linear Probing:
Initially the average number of probes are only slightly greater than 1 because the hash table is relatively empty. However they increase exponentially after alpha >= 0.6, because clustering has happened inside the table, and the number of probes required to find an empty slot increase.

Quadratic Probing:
Even though the average number of collisions increase with increasing alpha the jump is not as large and because this method prevents clustering inside the hash table.

Therefore, quadratic probing is much better than linear probing. However, in case we have to search elements in a large input Separate chaining may be preferred as it takes the least time.

<Note>
An image of the plot of the number of probes has been attatched in the analysis folder.

<Time Analysis>

Separate Chaining:
For 1000 runs, the code took 4.51 seconds to run the insert function, clearly indidcating that Linked Lists should not be preffered when dealing with large number of collisons.

Linear Probing:
Despite the clustering, 1000 runs of the code took 3.93 seconds, which is slightly better than separate chaining. However, searching in linear probing is extremely inefficient as was seen during question 2 of this assignment where we preffered separate chaining.

Quadratic Probing:
Quadratic Probing(with rehashing) was the clear winner when analysing the time taken to Insert elements, as even 1000 runs of this code took just 0.01 seconds! Hence, it is obvious that this method for resolving collisions is the best by far and should be preffered.

