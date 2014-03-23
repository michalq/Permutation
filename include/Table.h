#ifndef TABLE_H
#define TABLE_H

class Table
{
    public:
        Table(int tableWidth, int tableHeight);
        /**
         * Setters
         */
        int setTableWidth(int tableWidth);
        int setTableHeight(int tableHeight);
        /**
         * Getters
         */
        int  getTableWidth();
        int  getTableHeight();
        char **getTable();

        void appendData(bool showTable);
        void cleanTable(bool showTable);
        void showTable();
    private:
        int tableWidth;
        int tableHeight;
        char **tab;
        char appendChar(int i, int j, char z);
};

#endif // TABLE_H
