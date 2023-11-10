/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #7 (P2)

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
// defines/macros
#define LBS_TO_KG 2.20462
#define G_TO_KG 1000

#define NUMBER_OF_CAT_FOOD 3
#define NUMBER_TEST_ARRAY_SIZE 3
#define SERVIGING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    double weight;
    int caloriesPerServing;
};

struct ReportData
{
    int sku;
    double price;
    int caloriesPerServing;
    double weightLbs;
    double weightKg;
    int weightGrm;
    double totalServing;
    double costPerServing;
    double costPerCal;
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
void openingMessage(const int numberOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNumber);

// 5. Display the formatted table header
void displayCatFoodData(const int sku, const double *price, const double *weight, const int caloriesPerServing);

// 6. Display a formatted record of cat food data
void displayCatFoodHeader(void);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbs, double *result);

// 9. convert lbs: g
int convertLbsG(const double *lbs, int *result);

// 10. convert lbs: kg / g
void convertLbs(const double *lbs, double *kgResult, int *gResult);

// 11. calculate: servings based on gPerServ

// 12. calculate: cost per serving

// 13. calculate: cost per calorie

// 14. Derive a reporting detail record based on the cat food product data

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

// 17. Display the findings (cheapest)

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
