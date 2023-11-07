/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #8 (P1)

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZBB

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////
*/

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    double weight;
    int caloriesPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number);

// 3. Opening Message (include the number of products that need entering)
void getCatFoodInfo(struct CatFoodInfo *product, int productNumber);

// 4. Get user input for the details of cat food product
void openingMessage(void);

// 5. Display the formatted table header
void displayCatFoodData(struct CatFoodInfo catFoodArray[]);

// 6. Display a formatted record of cat food data
void displayCatFoodHeader(void);

// 7. Logic entry point
void start(void);
