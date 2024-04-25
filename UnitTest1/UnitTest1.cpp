#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.2/lab12.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(DuplicatePair_WithAdjacentDuplicates_ReturnsTrue) {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 2, 4, 5, 6 };
            int size = sizeof(values) / sizeof(values[0]);

            CreateList(head, tail, values, size);

            bool result = DuplicatePair(head);

            Assert::IsTrue(result, L"Expected true when list has adjacent duplicate elements");

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

        TEST_METHOD(DuplicatePair_WithoutAdjacentDuplicates_ReturnsFalse) {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 3, 4, 5, 6 }; 
            int size = sizeof(values) / sizeof(values[0]);

            CreateList(head, tail, values, size);

            bool result = DuplicatePair(head);

            Assert::IsFalse(result, L"Expected false when list does not have adjacent duplicate elements");

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
	};
}