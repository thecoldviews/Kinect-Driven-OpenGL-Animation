#include "Filters.h"
#include "qdebug.h"

Filter::Filter()
{
    count=0;
    windowsize=5;
    debug=false;
    step=2;
}

std::vector< std::map <int, std::pair<double, double> > > Filter::doFilter(std::vector< std::map <int, std::pair<double, double> > > frames ){

    count=0;
    if (debug) qDebug("Deubgw: '%d'", windowsize);
    std::vector< std::map <int, std::pair<double, double> > > filteredframes;
    while(count+windowsize<frames.size()){
        std::map <int, std::pair<double, double> >  instance;
        for(int j=0;j<20;j++){
              std::pair<double, double> p;
              p.first=0;
              p.second=0;
              instance[j+1]=p;
        }
        int count2=0;
        while(count2<windowsize){
            std::map <int, std::pair<double, double> >  current=frames.at(count+count2);
            for(int j=0;j<20;j++){
                  std::pair<double, double> p3 =current[j+1];
                  std::pair<double, double> p4 =instance[j+1];
                  p4.first=p4.first+p3.first;
                  p4.second=p4.second+p3.second;
                  instance[j+1]=p4;
            }
            count2++;
        }
        for(int j=0;j<20;j++){
              std::pair<double, double> p2 =instance[j+1];
              p2.first=p2.first/windowsize;
              p2.second=p2.second/windowsize;
              instance[j+1]=p2;
        }
        filteredframes.push_back(instance);
        count+=step;
    }

    return filteredframes;
}
