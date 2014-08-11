#include <stdlib.h>
#include <check.h>
#include <datastructs.h>


START_TEST (test_linked_list_create)
{
    ds_linked_list* list = ds_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    free(list);
}
END_TEST

START_TEST (test_linked_list_delete_empty)
{
    ds_linked_list* list = ds_linked_list_create();
    ds_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_linked_list_add_get_first)
{
    int a = 1;
    int* data = NULL;
    
    // list creation:
    ds_linked_list* list = ds_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    
    ds_linked_list_add(list, &a);
    ck_assert_int_eq(ds_linked_list_length(list), 1);
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    ds_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_linked_list_add_multiple_get_index)
{

    typedef struct user_data {
        char name[100];
        char email[100];
    } user_data;
    
    user_data a = {"John Doe", "john.doe@mail_server.com"};
    user_data b = {"Jack Smith", "jack.smith@mail_server.com"};
    user_data c = {"Jane Plain", "jane.plain@mail_server.com"};
    user_data d = {"Mary Merry", "mary.merry@mail_server.com"};
    
    user_data* data = NULL;
    
    // list creation:
    ds_linked_list* list = ds_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    
    ds_linked_list_add(list, &a);
    ds_linked_list_add(list, &b);
    ds_linked_list_add(list, &c);
    ds_linked_list_add(list, &d);
    ck_assert_int_eq(ds_linked_list_length(list), 4);
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    data =  ds_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    
    ds_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


START_TEST (test_linked_list_insert_at)
{

    typedef struct user_data {
        char name[100];
        char email[100];
    } user_data;
    
    user_data a = {"John Doe", "john.doe@mail_server.com"};
    user_data b = {"Jack Smith", "jack.smith@mail_server.com"};
    user_data c = {"Jane Plain", "jane.plain@mail_server.com"};
    user_data d = {"Mary Merry", "mary.merry@mail_server.com"};
    user_data e = {"Peter Pan", "peter.pan@mail_server.com"};
    user_data f = {"George Curious", "george.curious@mail_server.com"};
    
    user_data* data = NULL;
    
    // list creation:
    ds_linked_list* list = ds_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    
    ds_linked_list_insert_at(list, &b, 0);
    ds_linked_list_add(list, &c);
    ds_linked_list_add(list, &d);
    ds_linked_list_insert_at(list, &a, -5);
    ds_linked_list_insert_at(list, &e, 5);
    ds_linked_list_insert_at(list, &f, 150);

    ck_assert_int_eq(ds_linked_list_length(list), 6);
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    data =  ds_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    data =  ds_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    data =  ds_linked_list_get(list, 3);
    ck_assert_ptr_eq(data, &d);
    data =  ds_linked_list_get(list, 4);
    ck_assert_ptr_eq(data, &e);
    data =  ds_linked_list_get(list, 5);
    ck_assert_ptr_eq(data, &f);
    
    ds_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_linked_list_create_add_get_remove_clear_delete)
{
    int a = 1;
    int b = 2;
    int c = 3;
    
    int* data = NULL;
    
    
    // list creation:
    ds_linked_list* list = ds_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    
    // add '1'
    ds_linked_list_add(list, &a);
    ck_assert_int_eq(ds_linked_list_length(list), 1);
    
    // get '1'
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    
    // add '2'
    
    ds_linked_list_add(list, &b);
    ck_assert_int_eq(ds_linked_list_length(list), 2);
    
    // get '2'
    
    data =  ds_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    
    // add '3'
    
    ds_linked_list_add(list, &c);
    ck_assert_int_eq(ds_linked_list_length(list), 3);
    
    // get '3'
    
    data =  ds_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    
    // remove '3'
    
    ds_linked_list_remove(list, 2);
    ck_assert_int_eq(ds_linked_list_length(list), 2);
    
    // get '2'
    
    data =  ds_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    
    // get last element (index larger than list size)
    
    data =  ds_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &b);
    
    // get last element (index larger than list size)
    
    data =  ds_linked_list_get(list, 5);
    ck_assert_ptr_eq(data, &b);
    
    // get first element (negative index)
    
    data =  ds_linked_list_get(list, -10);
    ck_assert_ptr_eq(data, &a);
    
    // add '3'
    
    ds_linked_list_add(list, &c);
    ck_assert_int_eq(ds_linked_list_length(list), 3);
    
    // remove '1'
    
    ds_linked_list_remove(list, 0);
    ck_assert_int_eq(ds_linked_list_length(list), 2);
    
    // get first element (now '2')
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &b);
    
    // remove with negative index - does nothing
    
    ds_linked_list_remove(list, -1);
    ck_assert_int_eq(ds_linked_list_length(list), 2);
    
    // get first element (should still be '2')
    
    data =  ds_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &b);
    
    // clear the list - size should be zero
    
    ds_linked_list_clear(list);
    ck_assert_int_eq(ds_linked_list_length(list), 0);
    
    // delete the list - it should now point to NULL
    
    ds_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_doubly_linked_list_create)
{
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    free(list);
}
END_TEST

START_TEST (test_doubly_linked_list_delete_empty)
{
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ds_doubly_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_doubly_linked_list_add_get_first)
{
    int a = 1;
    int* data = NULL;
    
    // list creation:
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    
    ds_doubly_linked_list_add(list, &a);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 1);
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    ds_doubly_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_doubly_linked_list_add_multiple_get_index)
{

    typedef struct user_data {
        char name[100];
        char email[100];
    } user_data;
    
    user_data a = {"John Doe", "john.doe@mail_server.com"};
    user_data b = {"Jack Smith", "jack.smith@mail_server.com"};
    user_data c = {"Jane Plain", "jane.plain@mail_server.com"};
    user_data d = {"Mary Merry", "mary.merry@mail_server.com"};
    
    user_data* data = NULL;
    
    // list creation:
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    
    ds_doubly_linked_list_add(list, &a);
    ds_doubly_linked_list_add(list, &b);
    ds_doubly_linked_list_add(list, &c);
    ds_doubly_linked_list_add(list, &d);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 4);
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    data =  ds_doubly_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    
    ds_doubly_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


START_TEST (test_doubly_linked_list_insert_at)
{

    typedef struct user_data {
        char name[100];
        char email[100];
    } user_data;
    
    user_data a = {"John Doe", "john.doe@mail_server.com"};
    user_data b = {"Jack Smith", "jack.smith@mail_server.com"};
    user_data c = {"Jane Plain", "jane.plain@mail_server.com"};
    user_data d = {"Mary Merry", "mary.merry@mail_server.com"};
    user_data e = {"Peter Pan", "peter.pan@mail_server.com"};
    user_data f = {"George Curious", "george.curious@mail_server.com"};
    
    user_data* data = NULL;
    
    // list creation:
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    
    ds_doubly_linked_list_insert_at(list, &b, 0);
    ds_doubly_linked_list_add(list, &c);
    ds_doubly_linked_list_add(list, &d);
    ds_doubly_linked_list_insert_at(list, &a, -5);
    ds_doubly_linked_list_insert_at(list, &e, 5);
    ds_doubly_linked_list_insert_at(list, &f, 150);

    ck_assert_int_eq(ds_doubly_linked_list_length(list), 6);
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    data =  ds_doubly_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    data =  ds_doubly_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    data =  ds_doubly_linked_list_get(list, 3);
    ck_assert_ptr_eq(data, &d);
    data =  ds_doubly_linked_list_get(list, 4);
    ck_assert_ptr_eq(data, &e);
    data =  ds_doubly_linked_list_get(list, 5);
    ck_assert_ptr_eq(data, &f);
    
    ds_doubly_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST

START_TEST (test_doubly_linked_list_create_add_get_remove_clear_delete)
{
    int a = 1;
    int b = 2;
    int c = 3;
    
    int* data = NULL;
    
    
    // list creation:
    ds_doubly_linked_list* list = ds_doubly_linked_list_create();
    ck_assert_ptr_ne(list, NULL);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    
    // add '1'
    ds_doubly_linked_list_add(list, &a);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 1);
    
    // get '1'
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &a);
    
    
    // add '2'
    
    ds_doubly_linked_list_add(list, &b);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 2);
    
    // get '2'
    
    data =  ds_doubly_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    
    // add '3'
    
    ds_doubly_linked_list_add(list, &c);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 3);
    
    // get '3'
    
    data =  ds_doubly_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &c);
    
    // remove '3'
    
    ds_doubly_linked_list_remove(list, 2);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 2);
    
    // get '2'
    
    data =  ds_doubly_linked_list_get(list, 1);
    ck_assert_ptr_eq(data, &b);
    
    // get last element (index larger than list size)
    
    data =  ds_doubly_linked_list_get(list, 2);
    ck_assert_ptr_eq(data, &b);
    
    // get last element (index larger than list size)
    
    data =  ds_doubly_linked_list_get(list, 5);
    ck_assert_ptr_eq(data, &b);
    
    // get first element (negative index)
    
    data =  ds_doubly_linked_list_get(list, -10);
    ck_assert_ptr_eq(data, &a);
    
    // add '3'
    
    ds_doubly_linked_list_add(list, &c);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 3);
    
    // remove '1'
    
    ds_doubly_linked_list_remove(list, 0);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 2);
    
    // get first element (now '2')
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &b);
    
    // remove with negative index - does nothing
    
    ds_doubly_linked_list_remove(list, -1);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 2);
    
    // get first element (should still be '2')
    
    data =  ds_doubly_linked_list_get(list, 0);
    ck_assert_ptr_eq(data, &b);
    
    // clear the list - size should be zero
    
    ds_doubly_linked_list_clear(list);
    ck_assert_int_eq(ds_doubly_linked_list_length(list), 0);
    
    // delete the list - it should now point to NULL
    
    ds_doubly_linked_list_delete(&list);
    ck_assert_ptr_eq(list, NULL);
}
END_TEST


Suite * linked_list_suite () {

    Suite *s = suite_create ("datastructs");

    TCase *tc_linked_list = tcase_create ("linked_list");
    
    tcase_add_test (tc_linked_list, test_linked_list_create);
    tcase_add_test (tc_linked_list, test_linked_list_delete_empty);
    tcase_add_test (tc_linked_list, test_linked_list_add_get_first);
    tcase_add_test (tc_linked_list, test_linked_list_add_multiple_get_index);
    tcase_add_test (tc_linked_list, test_linked_list_insert_at);
    tcase_add_test (tc_linked_list, test_linked_list_create_add_get_remove_clear_delete);
    
    TCase *tc_doubly_linked_list = tcase_create ("doubly_linked_list");
    
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_create);
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_delete_empty);
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_add_get_first);
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_add_multiple_get_index);
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_insert_at);
    tcase_add_test (tc_doubly_linked_list, test_doubly_linked_list_create_add_get_remove_clear_delete);

    suite_add_tcase (s, tc_linked_list);
    suite_add_tcase (s, tc_doubly_linked_list);

    return s;
  
}

int main (void) {

    int number_failed;
    
    Suite *s = linked_list_suite ();
    
    SRunner *sr = srunner_create (s);
    srunner_run_all (sr, CK_NORMAL);
    
    number_failed = srunner_ntests_failed (sr);
    
    srunner_free (sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

