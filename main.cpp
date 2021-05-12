#include <gtk/gtk.h>
#include "GTKRuler3/gtkhruler.h"
#include "GTKRuler3/gtkvruler.h"
#include "GTKRuler3/gtkruler.h"

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *hruler = gtk_hruler_new();
    gtk_ruler_set_metric(GTK_RULER(hruler), GTK_PIXELS);
    gtk_ruler_set_range(GTK_RULER(hruler), 0, 200, 0, 200);

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    table = gtk_table_new(3, 2, FALSE);
    gtk_container_add(GTK_CONTAINER(window), table);

    gtk_container_add(GTK_CONTAINER(table), hruler);

    gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}