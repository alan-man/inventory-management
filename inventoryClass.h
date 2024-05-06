#ifndef inv_H
#define inv_H

#include <iostream>
#include <vector>
#include "productClass.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;


class ProductNotFoundException : public exception {
private:
    string errorMessage;

public:
    explicit ProductNotFoundException(const string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

};

class Inventory {

private:
    vector<Product> products;

public:
    void addProduct(Product product){
        for (Product p : products){
            if (p.getID() == product.getID()){
                p.setQuantity(p.getQuantity() + product.getQuantity());
                cout << "Product already in inventory, its quantity was added" << endl;
                return;
            }
        }
        products.push_back(product);
        cout << "product "<< product.getName() <<" added to inventory" << endl;
    }

    void removeProduct(int id){
        for(auto p = products.begin();p != products.end(); p++){
            if(p->getID() == id){
                products.erase(p);
                cout << "Product removed" << endl;     
                return;           
            }
        }
        throw ProductNotFoundException("product id = " + to_string(id) + " not found in inventory");
    }

    Product* findProduct(int id){
        for(auto p = products.begin(); p != products.end();p++){
            if(p->getID() == id){
                return &(*p);
            }
        } 
        cout << "product not found" << endl;
        return nullptr;
    }

    void printInv() const{
        for(auto p=products.begin();p!=products.end();p++){
            cout<<"ID : "<<p->getID()<<endl;
            cout<<"Name : "<<p->getName()<<endl;
            cout<<"Category : "<<p->getCategory()<<endl;
            cout<<"Price : $"<<p->getPrice()<<endl;
            cout<<"Quantity : "<<p->getQuantity()<<endl;
            cout<<"Date : "<<p->getExpDate()<<endl;
        }
    }

    double getTotalInventoryValue(){
        double total = 0.0;
        for (Product product : products){
            total += product.getPrice() * product.getQuantity();
        }
        return total;
    }


    void saveInvFile(string filename){
        ofstream f;
        f.open(filename,ios::out);
        for( int i = 0; i < products.size();i++){
            Product p = products[i];
            f << p.getID() <<"," << p.getName() <<","  << p.getCategory()  <<"," << p.getPrice() <<"," << p.getQuantity()  <<"," << p.getExpDate() << endl;
        }
        f.close();
    }

    void loadInvFile(string filename){
        ifstream f;
        f.open(filename);
        if(f.is_open()){
            string line;
            while (getline(f,line)){
                stringstream ss(line);
                string idS, nameS,categoryS,priceS,quantityS,dateS;
                getline(ss,idS,',');
                getline(ss,nameS,',');
                getline(ss,categoryS,',');
                getline(ss,priceS,',');
                getline(ss,quantityS,',');
                getline(ss,dateS,',');

                int id = stoi(idS);
                int quantity = stoi(quantityS);
                double price = stod(priceS);
                Product p(id,nameS,price,quantity,categoryS,dateS);
                products.push_back(p);
            }
            f.close();
        } else{
            cout << "file not found" << endl;
        }

    }

    void sortQuantity(){
        sort(products.begin(),products.end(),[](const Product& a,const Product& b) {
            return a.getQuantity() < b.getQuantity();
        });
    }



};


#endif

