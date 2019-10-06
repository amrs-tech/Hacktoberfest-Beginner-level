/**
 * This is a program to find largest positive of the given numbers
 * The user can pass as many numbrs thay want, as parameters
 */

const findLargestPositive = (...nums) => {
    /**
     * Used Rest operator to store all numbers passed, in an array
     * Used filter to filter to filter out only positive number
     * Sorted the numbers in descending order and returned the first element
     */
    return nums.filter(num => num > 0).sort((n1, n2) => n1 < n2)[0];
};