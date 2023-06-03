#include <iostream>
#include <chrono>

void arrayPrint(int arr[], int n)
{
    std::cout << "[ ";

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void insertionSort(int a[], int size) {
    int currentPlace = 0;
    int valueToInsert = 0;
    for (int i = 1; i < size; i++)
    {
        valueToInsert = a[i];
        currentPlace = i;
        while ((currentPlace > 0) && (a[currentPlace - 1] > valueToInsert))
        {
            a[currentPlace] = a[currentPlace - 1];
            currentPlace = currentPlace - 1;
        }
        a[currentPlace]= valueToInsert;
    }
}

/* int binarySearch(int a[], int x, int size) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = 0;
        mid = (low + high) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (x < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
} */

//bonus question
bool binarySearch(int a[], int x, int low, int high) {
    if (low > high) {
        return false;
    }
    else {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            return true;
        }
        else if (x > a[mid]) {
            binarySearch(a, x, (mid+1), high);
        }
        else if (x < a[mid]) {
            binarySearch(a, x, low, (mid-1));
        }
    }
    return false;
}

int runSortSearch()
{

    // -------- RESULTS --------------

    // generate random array
    // your code will be tested on a size of 10,000
    int dataSize = 10;
    int startingArray[dataSize];
    for (int i = 0; i < dataSize; i++)
    {
        startingArray[i] = rand() % 100;
    }
    std::cout << "Unsorted: ";
    arrayPrint(startingArray, dataSize);

    // --------- SORT --------------------
    auto startSort = std::chrono::high_resolution_clock::now();

    insertionSort(startingArray, dataSize);

    auto endSort = std::chrono::high_resolution_clock::now();
    auto totalSort = std::chrono::duration_cast<std::chrono::microseconds>(endSort - startSort);

    // -------- SEARCH ----------------------
    int elementToFind = 42;
    auto startSearch = std::chrono::high_resolution_clock::now();

    binarySearch(startingArray, elementToFind, 0, dataSize-1);

    auto endSearch = std::chrono::high_resolution_clock::now();
    auto totalSearch = std::chrono::duration_cast<std::chrono::microseconds>(endSearch - startSearch);

    // --------- RESULTS ---------------------
    std::cout << "Sorted: ";
    arrayPrint(startingArray, dataSize);

    std::cout << "Sort Time: " << totalSort.count() << std::endl;
    std::cout << "Search Time: " << totalSearch.count() << std::endl;

    return totalSearch.count() + totalSort.count();
}


int main()
{

    int avgtime = 0;

    for (int i = 0; i < 3; i++)
    {
        srand(i);
        avgtime += runSortSearch();
    }

    std::cout << "FINAL SCORE: " << avgtime / 3 << std::endl;
}