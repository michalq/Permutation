#include<stdio.h>
#include "Table.h"

void Table::cleanTable(bool showTable = false)
{
    int width = this->getTableWidth();
    int height = this->getTableHeight();
    char **tab = getTable();
    for (int i = 1; i < width; i++)
    {
        for (int j = 1; j < height; j++)
        {
            tab[i][j] = '-';
        }
    }
    if (showTable)
        this->showTable();
}

void Table::appendData(bool showTable = false)
{
    int c_vert_1, // first vertex
        c_vert_2; // second vertex
    char c_char; // char > | < | -
    char c_name; // name of the bond

    do
    {
        scanf("%c[^' ']", &c_name);
        printf(":%c:", c_name);
        if (c_name == '0')
        {
            break;
        }
        scanf("%i", &c_vert_1);
        scanf("%c['<','>','-']", &c_char);
        scanf("%i\n", &c_vert_2);
        fflush(stdin);
        /*
         * Appending data to ^2 table
         */
        if (c_char == '>' || c_char == '-')
        {
            this->appendChar(c_vert_1, c_vert_2, c_name);
        }

        if (c_char == '<' || c_char == '-')
        {
            this->appendChar(c_vert_2, c_vert_1, c_name);
        }
    }while(true);

    if (showTable)
        this->showTable();
}

void Table::showTable()
{
    int width = this->getTableWidth();
    int height = this->getTableHeight();
    printf("\n");
    for (int i = 1; i < width; i++)
    {
        for (int j = 1; j < height; j++)
        {
            printf("%c\t", tab[i][j]);
        }
        printf("\n");
    }
}

/**
 * Constructor, setters, getters and rest of this whole shit
 */
Table::Table(int tableWidth, int tableHeight)
{
    this->setTableWidth(tableWidth);
    this->setTableHeight(tableHeight);
    this->tab = new char *[tableWidth];
    for(int i = 0; i < tableWidth; i++)
    {
       this->tab[i] = new char [tableHeight];
    }
    this->cleanTable();
}

int Table::setTableWidth(int tableWidth)
{
    return this->tableWidth = tableWidth;
}

int Table::setTableHeight(int tableHeight)
{
    return this->tableHeight = tableHeight;
}

int Table::getTableWidth()
{
    return this->tableWidth;
}

int Table::getTableHeight()
{
    return this->tableHeight;
}

char **Table::getTable()
{
    return this->tab;
}

char Table::appendChar(int i, int j, char z)
{
    return this->tab[i][j] = z;
}
