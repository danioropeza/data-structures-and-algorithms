#include "List8.h"

template<typename T>
List8<T>::List8() {
	first_ = NULL;
	last_ = NULL;
}
template<typename T>
Triple<T>* List8<T>::first() {
	return first_;
}
template<typename T>
Triple<T>* List8<T>::last() {
	return last_;
}
template<typename T>
void List8<T>::AddFront(T element) {
	Triple<T>* aux;
	if (first_ == NULL) {
		first_ = last_ = new Triple<T>(element);
	}
	else {
		aux = first_;
		first_ = new Triple<T>(element);
		first_->set_next(aux);
		aux->set_previous(first_);
	}
}
template<typename T>
void List8<T>::DeleteFront() {
	Triple<T>* aux;
	if (first_ != NULL) {
		if (first_ == last_) {
			delete first_;
			last_ = first_ = NULL;
		}
		else
		{
			aux = first_->next();
			delete first_;
			first_ = aux;
			first_->set_previous(NULL);
		}
	}
}
template<typename T>
void List8<T>::AddBack(T element) {
	Triple<T>* aux;
	if (last_ == NULL) {
		first_ = last_ = new Triple<T>(element);
	}
	else {
		aux = last_;
		last_ = new Triple<T>(element);
		last_->set_previous(aux);
		aux->set_next(last_);
	}
}
template<typename T>
void List8<T>::DeleteBack() {
	Triple<T>* aux;
	if (last_ != NULL) {
		if (first_ == last_) {
			delete last_;
			last_ = first_ = NULL;
		}
		else
		{
			aux = last_->previous();
			delete last_;
			last_ = aux;
			last_->set_next(NULL);
		}
	}
}
template<typename T>
Triple<T>* List8<T>::Search(T element) {
	Triple<T>* iterator = first_;
	while (iterator != NULL) {
		if (element == iterator->element()) {
			return iterator;
		}
		iterator = iterator->next();
	}
	return NULL;
}
template<typename T>
Triple<T>* List8<T>::SearchRecursiveImpl(T element, Triple<T>* iterator) {
	if (iterator == NULL) {
		return NULL;
	}
	if (element == iterator->element()) {
		return iterator;
	}
	else {
		return SearchRecursiveImpl(element, iterator->next());
	}
}
template<typename T>
Triple<T>* List8<T>::SearchRecursive(T element) {
	return SearchRecursiveImpl(element, first_);
}
template<typename T>
Triple<T>* List8<T>::SearchTheMinor() {
	Triple<T>* iterator = first_;
	Triple<T>* minor = first_;
	while (iterator != NULL) {
		if (iterator->element() < minor->element()) {
			minor = iterator;
		}
		iterator = iterator->next();
	}
	return minor;
}
template<typename T>
Triple<T>* List8<T>::Nth(int position) {
	if (position < 0) {
		return NULL;
	}
	Triple<T>* iterator = first_;
	int index = 1;
	while (iterator != NULL && index < position) {
		iterator = iterator->next();
		index++;
	}
	return iterator;
}
template<typename T>
void List8<T>::ShowList() {
	cout << "List Values: " << endl;
	Triple<T>* iterator = first_;
	while (iterator != NULL) {
		iterator->ShowElement();
		iterator = iterator->next();
		if (iterator != NULL) { cout << " -> "; }
	}
	cout << endl << endl;
}