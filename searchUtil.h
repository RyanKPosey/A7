/**
 * @file searchUtil.h
 * @brief Header-only utility template for linear array searching.
 */
#ifndef SEARCHUTIL_H
#define SEARCHUTIL_H

/**
 * @brief Perform a linear search on an array of type @p T.
 *
 * Iterates from index 0 to index @p size - 1 and compares each element
 * with @p target using the equality operator.
 *
 * @tparam T Element type stored in the array.
 * @param arr Array to search.
 * @param size Number of valid elements in @p arr.
 * @param target Value to locate in the array.
 * @return Index of the first matching element, or -1 if no match is found.
 */
template <typename T>
int linearSearch(T arr[], int size, T target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

#endif // SEARCHUTIL_H
