/**
 * Created by: Michal Kutrzeba
 */
#include "Node.h"

Node::Node()
{
    this->setName('\0');
    this->setFrom(0);
    this->setTo(0);
    this->setWeight(0);
    this->status = true;
}

Node::Node(char name, int from, int to, int weight/* = 1*/)
{
    this->setName(name);
    this->setFrom(from);
    this->setTo(to);
    this->setWeight(weight);
    this->status = true;
}
/**
 * Setters
 */
void Node::setFrom(int from)
{
    this->from = from;
}

void Node::setTo(int to)
{
    this->to = to;
}

void Node::setName(char name)
{
    this->name = name;
}

void Node::setWeight(float weight)
{
    this->weight = weight;
}

/**
 * Getters
 */
int Node::getFrom()
{
    return this->from;
}

int Node::getTo()
{
    return this->to;
}

char Node::getName()
{
    return this->name;
}

float Node::getWeight()
{
    return this->weight;
}

bool Node::getStatus()
{
    return this->status;
}

