/**
 * Created by: Michal Kutrzeba
 */
#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(char name, int from, int to, int weight = 1);
        Node();
        void setFrom(int from);
        void setTo(int to);
        void setName(char name);
        void setWeight(float weight);
        int getFrom();
        int getTo();
        char getName();
        float getWeight();
        bool getStatus();

    private:
        int from;
        int to;
        char name;
        float weight;
        bool status;
};

#endif // NODE_H
