template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // clear just in case (not strictly necessary since we use this in ctor/assignment)
    head = nullptr;
    this->length = 0;

    if (copyObj.head == nullptr) {
        return; // nothing to copy
    }

    // copy first node
    head = new Node(copyObj.head->value);
    this->length = 1;

    Node* currNew = head;
    Node* currOld = copyObj.head->next;

    while (currOld != nullptr) {
        currNew->next = new Node(currOld->value);
        currNew = currNew->next;
        currOld = currOld->next;
        this->length++;
    }
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }

    Node* n = new Node(elem);

    // insert at front
    if (position == 0) {
        n->next = head;
        head = n;
    }
    else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }

    Node* toDelete = nullptr;

    if (position == 0) {
        toDelete = head;
        head = head->next;
    }
    else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        toDelete = curr->next;
        curr->next = toDelete->next;
    }

    delete toDelete;
    this->length--;
}
