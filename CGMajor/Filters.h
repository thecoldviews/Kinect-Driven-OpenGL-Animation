#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <map>

class Filter
{
private:
    bool debug;
    int windowsize;
    int count;
    int step;
public:

    Filter();
    std::vector< std::map <int, std::pair<double, double> > > doFilter(std::vector< std::map <int, std::pair<double, double> > > );
    void setWindow(int w){
        this->windowsize=w;
    }

};

#endif // FILTER_H
