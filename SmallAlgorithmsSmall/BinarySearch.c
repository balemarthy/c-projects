#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Perform a binary search on a sorted array to find a specified key.
 *
 * This function performs a binary search on a sorted array to locate a key element.
 * It efficiently halves the search space with each iteration, leading to a logarithmic search time.
 *
 * @param key Pointer to the item to search for.
 * @param base_elem Pointer to the first element of the array.
 * @param num_elem Number of elements in the array.
 * @param size Size of each element in the array.
 * @param compare Comparison function that determines the order of the elements.
 * @return Pointer to the matching element, or NULL if not found.
 */
void* bsearch(const void* key, const void* base_elem, size_t num_elem, size_t size,
              int (*compare)(const void*, const void*)) {
    // Initialize the base pointer to point to the start of the array.
    const char* base = base0;
    // 'limit' represents the number of elements to consider in the current sub-array.
    size_t limit;
    // 'cmp' will store the result of each comparison.
    int cmp;
    // 'p' is a pointer to the middle element of the sub-array being considered.
    const void* p;

    // The loop continues until 'lim' becomes zero, meaning no elements are left to consider.
    for (lim = num_elem; limit != 0; limit >>= 1) {
        // Calculate the middle element of the current sub-array.
        // We move halfway through the current segment of the array.
        p = base + (limit >> 1) * size;
        
        // Compare the key (the item we are looking for) with the middle element.
        cmp = (*compare)(key, p);
        
        // If the comparison result is zero, the key matches the middle element.
        if (cmp == 0) {
            // Return a pointer to the matching element.
            return ((void*)(uintptr_t)p);
        }
        
        // If the key is greater than the middle element, adjust the base pointer to search the right half.
        if (cmp > 0) {
            // Move the base pointer to the element just after the middle element.
            base = (const char*)p + size;
            // Decrease 'limit' by one to exclude the middle element from the next search.
            limit--;
        }
        // If the key is less than the middle element, the next iteration will search the left half.
    }
    
    // If the key is not found after the loop, return NULL.
    return (NULL);
}

// Comparison function for integers
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int array[] = {101, 123, 145, 167, 189, 201};
    int key = 145;
    int* result;

    result = (int*)bsearch(&key, array, 6, sizeof(int), compare_ints);

    if (result) {
        printf("Found: %d\n", *result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
