#include <iostream>
using namespace std;

struct product{
    int p_id;
    float weight;
    float value;
};

void swap(product *a,product *b){
    product t = *a;
    *a = *b;
    *b = t;
}
int sort(product a[],int low,int high)
{
    product pivot = a[high];
    int i = -1;
    for(int j = 0;j<=high-1;j++){
        if((a[j].value/a[j].weight)<(pivot.value/pivot.weight)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quick_sort(product a[],int low,int high)
{
    if(low<=high)
    {
        int pivot = sort(a,low,high);
        quick_sort(a, low, pivot-1);
        quick_sort(a, pivot+1, high);
    }
}

typedef struct product product;
int main(){
    int n;
    cout << "Enter the number of values:";
    cin >> n;
    product products[n];
    for(int i = 0;i<n;i++){
        products[i].p_id = i;
        cout<<"Enter product weight: ";
        cin>>products[i].weight;
        cout<<"Enter product cost: ";
        cin>>products[i].value;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         if((products[j].value/products[j].weight)<(products[j+1].value/products[j+1].weight)){
    //             product temp = products[j];
    //             products[j] = products[j+1];
    //             products[j+1] = temp;
    //         }
    //     }
    // }

    quick_sort(products,0,n);

    for(int i = 0;i<n;i++){
        cout<<products[i].p_id<<" "<<products[i].value<<" "<<products[i].weight<<" "<<products[i].value/products[i].weight<<endl;
    }

    float bag;
    cout<<"Enter the bag weight: ";
    cin>>bag;
    int i = 0;
    float p = 0;
    while(bag>0){
        cout<< "Product taken: "<<products[i].p_id<<endl;
        if(products[i].weight<=bag){
            bag = bag - products[i].weight;
            p = p + products[i].value;
        }
        else{
            float fraction = bag/products[i].weight;
            bag = bag - fraction*products[i].weight;
            p = p + fraction*products[i].value;
        }
        i = i+1;
    }
    cout<<"Profit :"<<p;
    return 0;
}