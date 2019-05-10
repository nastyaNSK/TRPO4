#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <ctest.h>
#include <geometry.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(area_calculation_test, result_test)
{
    // Given
    circle f;
    f.radius = 4.5;

    // When
    const double result = area_calculation(&f);

    // Then
    const double expected = 63.617251;
    ASSERT_EQUAL(expected, result);
}

CTEST(perimeter_calculation_test, result_test)
{
    // Given
    circle f;
    f.radius = 1.5;

    // When
    const double result = perimeter_calculation(&f);

    // Then
    const double expected = 9.424778;
    ASSERT_EQUAL(expected, result);
}

CTEST(intersection_definition_test, same_center_coordinates_test)
{
    // Given
    circle f1, f2;
    f1.x = 3.17;
    f2.x = 3.17;
    f2.y = -10;
    f2.y = -10;

    // When
    const double result = intersection_definition(&f1, &f2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(intersection_definition_test, intersection_false)
{
    circle f1, f2;
    f1.x = 0;
    f1.y = 6;
    f1.radius = 2;
    f2.x = 7;
    f2.y = 6;
    f2.radius = 5;

    // When
    const double result = intersection_definition(&f1, &f2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(intersection_definition_test, intersection_true)
{
    circle f1, f2;
    f1.x = 0;
    f1.y = 6;
    f1.radius = 2;
    f2.x = 7;
    f2.y = 6;
    f2.radius = 5.1;

    // When
    const double result = intersection_definition(&f1, &f2);

    // Then
    ASSERT_TRUE(result);
}
