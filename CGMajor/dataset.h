#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <map>

class DataSet
{bool debug=false;
    bool running;
    int count;
    std::vector< std::map< int, std::pair<double,double> > > data;
public:
    DataSet(){
        count=0;
    }

    void fetchDataSet(int index);
    std::vector< std::map< int, std::pair<double,double> > > getData(){
        return data;
    }
    bool getRunning(){
        return running;
    }

    void setRunning(bool running){
        this->running=running;
    }

    void fetch();
    void clear();
};

#endif // DATASET_H
