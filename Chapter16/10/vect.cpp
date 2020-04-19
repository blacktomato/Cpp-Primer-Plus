// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool cheapThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rr);
void ShowReview(const std::shared_ptr<Review> rr);

int main() {
    using namespace std;
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp(new Review);
    while (FillReview(temp)){
        shared_ptr<Review> element (new Review);
        element->price = temp->price;
        element->title = temp->title;
        element->rating = temp->rating;
        books.push_back(element);
    }
    
    if (books.size() > 0) {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n";

        cout << "Rating\t" 
             << std::setw(25) << std::left << "Book"
             << "\tprice\n";
        for_each(books.begin(), books.end(), ShowReview);
        cout << endl;

        char mode;
        cout << "a. original order \t" << "b. alphabetical order\n"
             << "c. rating order(increasing)\t" << "d. rating order(decreasing)\n"
             << "e. price order(increasing)\t" << "f. price order(decreasing)\n"
             << "q. quit\n" << endl;
        vector<shared_ptr<Review>> v_temp;
        while(cin >> mode){
            if (mode == 'q') break;
            else {
                v_temp = vector<shared_ptr<Review>>(books.begin(), books.end());
                if (mode == 'a'){ // original order
                    cout << "Original order:\n";
                }
                else if (mode == 'b'){ //alphabeetical order
                    sort(books.begin(), books.end());
                    cout << "Sorted by title:\n";
                }
                else if (mode == 'c'){ //rating order(increasing)
                    sort(books.begin(), books.end(), worseThan);
                    cout << "Sorted by rating(increasing):\n";
                }
                else if (mode == 'd'){ //rating order(decreasing)
                    sort(books.rbegin(), books.rend(), worseThan);
                    cout << "Sorted by rating(decreasing):\n";
                }
                else if (mode == 'e'){ //price order(increasing)
                    sort(books.begin(), books.end(), cheapThan);
                    cout << "Sorted by price(increasing):\n";
                }
                else if (mode == 'f'){ //price order(decreasing)
                    sort(books.rbegin(), books.rend(), cheapThan);
                    cout << "Sorted by price(decreasing):\n";
                }
                else {
                    cerr << "Invalid input!" << endl;
                    continue;
                }
                cout << "Rating\t" << std::setw(24) << std::left << "Book"
                    << "\tprice\n";
                for_each(books.begin(), books.end(), ShowReview);
                cout << endl;
            } 
        }
    }
    else cout << "No entries. ";

    cout << "Bye.\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->title < r2->title) return true;
    else if (r1->title == r2->title && r1->rating < r2->rating) return true;
    else return false;
}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->rating < r2->rating) return true;
    else return false;
}

bool cheapThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2) {
    if (r1->price < r2->price) return true;
    else return false;
}

bool FillReview(std::shared_ptr<Review> rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit") return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    if (!std::cin) return false;
    std::cout << "Enter book price: ";
    std::cin >> rr->price;
    if (!std::cin) return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> rr) {
    std::cout << rr->rating << "\t" << std::setw(24) << std::left << rr->title << "\t" << rr->price << std::endl;
}