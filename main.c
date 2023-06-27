#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void inventario(int codigo[10], char *nombres[10], int cantidad[10], float precios[10]);
void ingresar_producto(int codigo[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10]);
int ingresar_producto_codigo(int codigo[10]);
char *ingresar_nombre_p(char *nombres[10], char nuevo_nombre[50]);
int ingresar_producto_cantidad(int cantidad[10]);
float ingresar_producto_precio(float precios[10]);
int modificar_cantidad(int codigo[10], int cantidad[10]);
int eliminar(int codigo[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10]);
void volver(char *atajo);

int main()
{
    int opciones;
    int codigo[10] = {11, 12, 13, 14, 0, 0, 0, 0, 0, 0};
    char *nombres[10] = {"Pastel_grande", "pan", "empanadas", "tiramissu", "------", "------", "------", "------", "------", "------"};
    int cantidad[10] = {1, 2, 1, 4, 0, 0, 0, 0, 0, 0};
    float precios[10] = {5.00, 0.25, 0.30, 2.50, 0, 0, 0, 0, 0, 0};
    char nuevo_nombre[50];
    char atajo;

    do
    {
        printf("\n-----------------MENU-------------\n");
        printf("1. Menu de inventario\n");
        printf("2. Ingresar nuevo producto al inventario max 10\n");
        printf("3. Modificar la cantidad de un producto\n");
        printf("4. Eliminar un producto \n");
        printf("5. Salir\n");
        printf("------------------------------------\n");
        printf("seleccione una opcion: ");
        scanf("%d", &opciones);

        switch (opciones)
        {
        case 1:
            inventario(codigo, nombres, cantidad, precios);
            volver(&atajo);
            break;
        case 2:
            ingresar_producto(codigo, nombres, nuevo_nombre, cantidad, precios);
            volver(&atajo);
            break;
        case 3:
            modificar_cantidad(codigo, cantidad);
            volver(&atajo);
            break;
        case 4:
            eliminar(codigo, nombres, nuevo_nombre, cantidad, precios);
            volver(&atajo);
            break;
        case 5:
            printf("\n~Esperamos tu visita pronto!\n");
            break;
        default:
            printf("Opción no valida, intenta de nuevo\n\n");
            break;
        }
    } while (opciones != 5);

    return 0;
}

void inventario(int codigo[10], char *nombres[10], int cantidad[10], float precios[10])
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~PASTELERIA~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" CODIGO          NOMBRE               CANTIDAD         PRECIO   \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    int ancho_nombre = 0;
    for (int i = 0; i < 10; i++)
    {
        int longitud = strlen(nombres[i]);
        if (longitud > ancho_nombre)
        {
            ancho_nombre = longitud;
        }
    }

    for (int i = 0; i < 10; i++)
    {

        if (codigo[i] < 10 && cantidad[i] < 10)
        {
            printf("   0%d           %-*s                0%d             $%.2f\n", codigo[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }

        else if (codigo[i] < 10)
        {
            printf("   0%d           %-*s                %d             $%.2f\n", codigo[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }

        else if (cantidad[i] < 10)
        {
            printf("   %d           %-*s                0%d             $%.2f\n", codigo[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }

        else
        {
            printf("   %d           %-*s                %d             $%.2f\n", codigo[i], ancho_nombre, nombres[i], cantidad[i], precios[i]);
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void ingresar_producto(int codigo[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{

    int contador = 0;
    for (int i = 0; i < 10; i++)
    {
        if (codigo[i] != 0)
        {
            contador += 1;
        }
    }

    if (contador < 10)
    {
        ingresar_producto_codigo(codigo);
        ingresar_nombre_p(nombres, nuevo_nombre);
        ingresar_producto_cantidad(cantidad);
        ingresar_producto_precio(precios);
        printf("\n");
    }

    else
    {
        printf("El inventario ya no tiene espacio max 10 productos.\n\n");
    } 
}

int ingresar_producto_codigo(int codigo[10])
{
    int codigo_nuevo;

    do
    {
        printf("\nInserta el codigo del nuevo producto: ");
        scanf("%d", &codigo_nuevo);

        for (int i = 0; i < 10; i++)
        {

            if (codigo_nuevo == codigo[i] || codigo_nuevo <= 0)
            {
                codigo_nuevo = 0;
            }
            else
            {
                if (codigo[i] == 0)
                {
                    return codigo[i] = codigo_nuevo;
                }
            }
        }

        if (codigo_nuevo == 0)
        {
            printf("Ese cogio ya es de otro producto. Inserta uno nuevo.\n");
        }
    } while (codigo_nuevo == 0);
}

char *ingresar_nombre_p(char *nombres[10], char nuevo_nombre[50])
{
    do
    {
        printf("crea e ingresa el nombre del nuevo producto: ");
        scanf("%s", nuevo_nombre);

        for (int i = 0; i < 10; i++)
        {

            if (strcmp(nuevo_nombre, nombres[i]) == 0)
            {
                strcpy(nuevo_nombre, "------");
                break;
            }

            else if (strcmp(nombres[i], "------") == 0)
            {
                return nombres[i] = strdup(nuevo_nombre);
            }
        }

      
        if (strcmp(nuevo_nombre, "------") == 0)
        {
            printf("Ese nombre ya corresponde a otro producto. Inserta uno nuevo.\n\n");
        }
    } while (strcmp(nuevo_nombre, "------") == 0);
}


int ingresar_producto_cantidad(int cantidad[10])
{
    int cantidad_nueva;

    do
    {
        printf("Inserta la cantidad del producto: ");
        scanf("%d", &cantidad_nueva);

        
        if (cantidad_nueva <= 0)
        {
            printf("La cantidad debe ser mayor a 0. Inserta otra vez.\n\n");
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            if (cantidad[i] == 0)
            {
                return cantidad[i] = cantidad_nueva;
            }
        }
    } while (cantidad_nueva == 0);
}


float ingresar_producto_precio(float precios[10])
{
    float precio_nuevo;

    do
    {
        printf("Inserta el precio del nuevo producto: ");
        scanf("%f", &precio_nuevo);

        
        if (precio_nuevo <= 0)
        {
            printf("El precio debe ser mayor a 0. Inserta otra vez.\n\n");
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            if (precios[i] == 0.0)
            {
                precios[i] = precio_nuevo;
                return precios[i];
            }
        }
    } while (precio_nuevo == 0.0);
}


int modificar_cantidad(int codigo[10], int cantidad[10])
{
    int codigo_producto;
    int posicion;
    int nueva_cantidad;

    printf("\nInserta el codigo del producto para cambiarla cantidad almacenada inventario: ");
    scanf("%d", &codigo_producto);

   
    if (codigo_producto == 0)
    {
        printf("El codigo 0 no existe.\n\n");
        return 1;
    }

    
    for (int i = 0; i < 10; i++)
    {
        if (codigo_producto == codigo[i])
        {
            posicion = i;
            break;
        }
        else if (i == 9)
        {
            
            codigo_producto = 0;
        }
    }

   
    if (codigo_producto == 0)
    {
        printf("No corresponde al codigo de ningun producto.\n\n");
        return 1;
    }

  
    do
    {
        printf("Inserta la nueva cantidad del producto: ");
        scanf("%d", &nueva_cantidad);
      
        if (nueva_cantidad == cantidad[posicion])
        {
            printf("Esa cantidad coincide con la del iventario. Ingresa una nueva.\n\n");
        }
        else
        {
          
            if (nueva_cantidad <= 0)
            {
                printf("La cantidad no puede ser 0 o menor. Inserta una nueva\n\n");
            }
            else
            {
                printf("\n");
                return cantidad[posicion] = nueva_cantidad;
            }
        }
    } while (cantidad[posicion] == nueva_cantidad || nueva_cantidad <= 0);
}


int eliminar(int codigo[10], char *nombres[10], char nuevo_nombre[50], int cantidad[10], float precios[10])
{
    int codigo_producto;
    int posicion;

    printf("\nIngresa el codigo del producto para eliminarlo del inventario: ");
    scanf("%d", &codigo_producto);

   
    if (codigo_producto == 0)
    {
        printf("El codigo no puede ser 0.\n\n");
        return 1;
    }

    
    for (int i = 0; i < 10; i++)
    {
        if (codigo_producto == codigo[i])
        {
            posicion = i;
            break;
        }
        else if (i == 9)
        {
            codigo_producto = 0;
        }
    }

    
    if (codigo_producto == 0)
    {
        printf("No es el codigo de un producto.\n\n");
        return 1;
    }

   
    codigo[posicion] = 0;
    nombres[posicion] = "------";
    cantidad[posicion] = 0;
    precios[posicion] = 0;
    printf("El producto ha sido eliminado\n\n");
    return 0;
}


void volver(char *atajo)
{
    do
    {
       
        printf("Presiona la tecla 's' para volver: ");
        scanf(" %c", atajo);

       
        if (!(isalpha(*atajo)))
        {
            printf("No es una letra. Intenta otra vez\n\n");
        }
       
        else if (!(*atajo == 's' || *atajo == 'S'))
        {
            printf("No es la letra 's'. Intenta otra vez\n\n");
        }
        
        else
        {
            system("cls");
            break;
        }
    } while (*atajo != 's' || *atajo != 'S');
}