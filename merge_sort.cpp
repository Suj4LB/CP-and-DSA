//Performing merge sort using file handling in c++ where we sort students according to their roll number
#include<bits/stdc++.h>
using namespace std;

const int MAX_STUDENTS = 5;

void merge(int arr[], int left, int mid, int right, string names[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    string leftNames[n1], rightNames[n2];
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
        leftNames[i] = names[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
        rightNames[i] = names[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            names[k] = leftNames[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            names[k] = rightNames[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        names[k] = leftNames[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        names[k] = rightNames[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, string names[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, names);
        mergeSort(arr, mid + 1, right, names);
        merge(arr, left, mid, right, names);
    }
}

int main(void) {
    // ofstream outFile("labfile.txt");
    // if (outFile.is_open()) {
    //     outFile << "101 Sujal\n";
    //     outFile << "103 Samar\n";
    //     outFile << "102 Sid\n";
    //     outFile << "105 Vansh\n";
    //     outFile << "104 Kavya\n";
    //     outFile.close();

    //     cout << "File 'labfile.txt' created and written successfully." << "\n";
    // } else {
    //     cout << "Error creating the file!" << "\n";
    // }
    ifstream inFile("labfile.txt");
    if (!inFile.is_open()) {
        cout << "Error opening the file!" << "\n";
    }
    int rollNumbers[MAX_STUDENTS];
    string names[MAX_STUDENTS];
    int numStudents = 0;
    while (numStudents < MAX_STUDENTS && inFile >> rollNumbers[numStudents] >> names[numStudents]) {
        numStudents++;
    }
    inFile.close();
    mergeSort(rollNumbers, 0, numStudents - 1, names);
    ofstream outFileSorted("sorted_labfile.txt");
    if (!outFileSorted.is_open()) {
        cerr << "Error opening the output file" << "\n";
        return 1;
    }
    for (int i = 0; i < numStudents; i++) {
        outFileSorted << rollNumbers[i] << " " << names[i] << "\n";
    }
    outFileSorted.close();
    cout << "File created and sorted successfully." << "\n";
    return 0;
}
