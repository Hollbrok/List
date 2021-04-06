#include "list.h"

using namespace std;

int main()
{
    CONSTRUCT(list_1);
    list_1.set_element_from_end(10);
    list_1.set_element_from_start(5);
    printf("end = [%lg]\n", (list_1.get_end())->get_data() );
    printf("start = [%lg]\n", (list_1.get_start())->get_data() );
    printf("next to start =[%lg]\n", list_1.get_start()->get_next()->get_data() );

    return 0;
}
