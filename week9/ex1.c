#include <stdio.h>
#include <stdlib.h>

typedef struct page{
    unsigned short age;
    unsigned short id;
}page;


page *pages;
int n;

void printPages(){
    for (int i = 0; i < n; i++){
        printf("i: %i\tid: %hu\tage: %hu\t\t%hx\n", i, pages[i].id, pages[i].age, pages[i].age);
    }
}

int main()
{
    scanf("%i", &n);
    pages = malloc(n*sizeof(page));
    for (int i = 0; i < n; i++){
        pages[i].age = 0;
    }
    
    int misses = 0;
    int hits=0;
    FILE * inp = fopen("input.txt", "r");
    int request;
    while (fscanf(inp, "%i", &request) != EOF){
        unsigned short minAge = -1;
        unsigned short minAgeN = -1;
        int pageFault = 1;
        for (int i = 0; i < n; i++){
            if (pages[i].id == request){
                minAgeN = i;
                pageFault = 0;
                break;
            }
            minAgeN = (minAge > pages[i].age ? i : minAgeN);
            minAge = (minAge > pages[i].age ? pages[i].age : minAge);
        }
        
        for (int i = 0; i < n; i++){
            pages[i].age >>= 1;
        }
        
        if (pageFault){
            pages[minAgeN].id = request;
            pages[minAgeN].age = 0x8000;
            misses++;
        }else{
            pages[minAgeN].age += 0x8000;
            hits++;
        }
        
        //printPages();
        //printf("page %i was added.\n\n", request);
    }
    
    printf("%i hits : %i misses\nhit ratio: %f %%", hits, misses, ((float)hits)/(hits+misses)*100);
    return 0;
}
