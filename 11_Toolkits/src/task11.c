#include <glib.h>
#include <glib/gprintf.h>
#include <gmodule.h>

#define MAX_LEN 80

typedef struct data {
   gchar* key;
   gint value;
} data_struct;

void 
print_hash(gpointer key, gpointer value, gpointer user_data) {
	g_printf("%s: %d\n", (gchar*)key, GPOINTER_TO_INT(value));
}

void 
print_data(gpointer data, gpointer user_data) {
	g_printf("%s: %d\n", (*((data_struct*)data)).key, (*((data_struct*)data)).value);
}

gint
data_compare(gconstpointer a, gconstpointer b) {
	if ((*((data_struct*)a)).value < (*((data_struct*)b)).value)
		return -1;
	else
	if ((*((data_struct*)a)).value == (*((data_struct*)b)).value)
		return 0;
	else
		return 1;
}

int
main(int argc, char** argv) {
	// THE STRING TO PARSE
	gchar* str = "one two one two three three four one five one two five two two";
	
	// PARSING THE STRING
	gchar** token_array = g_strsplit_set(str, " ", -1);
        gchar** dict_iterator = token_array;

	GHashTable* dictionary = g_hash_table_new(g_int_hash, g_str_equal);

	while(*dict_iterator != NULL) {
		
		gpointer void_value_p = g_hash_table_lookup(dictionary, *dict_iterator);
		if (!void_value_p)
			g_hash_table_insert(dictionary, *dict_iterator, GINT_TO_POINTER(1));
		else {
			gint value = GPOINTER_TO_INT(void_value_p);
			value++;
			g_hash_table_insert(dictionary, *dict_iterator, GINT_TO_POINTER(value));
		}
		
		dict_iterator++;
	}

	g_hash_table_foreach(dictionary, (GHFunc)print_hash, "");
	g_printf("\n");
	GList* list = NULL;
	
	GHashTableIter hash_iterator;
	gpointer key, value;
	
	g_hash_table_iter_init(&hash_iterator, dictionary);
	while(g_hash_table_iter_next (&hash_iterator, &key, &value)) {
		gchar* key_ref = (gchar*)key;

		gchar* key_v = (gchar*) g_malloc0(MAX_LEN);
	      	g_stpcpy(key_v, key_ref);
		gint value_v = GPOINTER_TO_INT(value);

		data_struct* data_piece = g_malloc0(MAX_LEN + sizeof(gint));
		(*data_piece).key = key_v;
		(*data_piece).value = value_v;

		list = g_list_append(list, data_piece);
	}

	GList* list_sorted = g_list_sort(list, (GCompareFunc)data_compare);
	g_list_foreach(list_sorted, (GFunc)print_data, "");

	g_printf("\nFINISH\n");
	return 0;
}
