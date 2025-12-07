template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    int currentIndex = i;
    while (currentIndex > 0) {
        int parentIndex = parent(currentIndex);
        if (data[currentIndex] < data[parentIndex]) {
            swap(data[currentIndex], data[parentIndex]);
            currentIndex = parentIndex;
        } else {
            break;
        }
    }

}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int currentIndex = i;
    int n = size();
    while (true) {
        int leftIndex = left(currentIndex);
        int rightIndex = right(currentIndex);
        int smallestIndex = currentIndex;

        if (leftIndex < n && data[leftIndex] < data[smallestIndex]) {
            smallestIndex = leftIndex;
        }
        if (rightIndex < n && data[rightIndex] < data[smallestIndex]) {
            smallestIndex = rightIndex;
        }
        if (smallestIndex != currentIndex) {
            swap(data[currentIndex], data[smallestIndex]);
            currentIndex = smallestIndex;
        } else {
            break;
        }
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    
    rootValue = data[0];
    swap(data[0], data.back());
    data.pop_back();
    siftDown(0);
    return rootValue;

}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then 
    // sift-down to restore heap property
    siftUp(index);
    siftDown(index);


}
