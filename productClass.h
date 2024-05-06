#ifndef prod_H
#define prod_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;
    string category;
    string expirationDate;

public:
    Product(int id, string name, double price, int quantity,string category,string expirationDate){
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->category = category;
        this->expirationDate = expirationDate;
    }

    int getID() const{ 
        return id;
    }

    string getName() const{ 
        return name;
    }
    
    double getPrice() const{ 
        return price;
    }

    int getQuantity() const{ 
        return quantity;
    }

    string getCategory() const{ 
        return category;
    }

    string getExpDate() const{ 
        return expirationDate;
    }


    void setId(int id) { 
        this->id = id;
    }
    
    void setName(){ 
        this->name = name;
    }

    void setPrice(double price){
        this->price = price;
    }

    void setQuantity(int quantity){
        this->quantity = quantity;
    }

    void setCategory(string category){
        this->category  = category;
    }

    void setExpDate(string expDate) { 
        this->expirationDate = expDate;
    }



























};

#endif





