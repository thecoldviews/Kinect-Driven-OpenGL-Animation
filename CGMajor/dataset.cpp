#include "dataset.h"
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sstream>
#include <qDebug.h>


void DataSet::fetchDataSet(int index)
{
      std::string folder = "C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Data\\";
      DIR *pDIR;
      struct dirent *entry;
      int count=0;
      std::vector <std::map<int, std::pair<double,double> > >frames;
      if( pDIR=opendir(folder.c_str()) ){
          while(entry = readdir(pDIR)){
              if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){

                  if(count==index){

                      std::string line;
                      std::string files = folder+entry->d_name;
                      std::ifstream myfile;
                      if(debug) qDebug("Deubg: '%s'", files.c_str());
                      myfile.open(files.c_str());
                      getline (myfile,line);
                      std::istringstream output(line);

                      int numframes;

                      output >> numframes;
                      if(debug) qDebug("Deubg: '%d'\n", numframes);
                      if (myfile.is_open())
                      {
                          std::map<int,std::pair<double,double> > newframe;
                          for(int i=0;i<numframes;i++)
                          {
                            getline (myfile,line);
                            std::istringstream output1(line);

                            int numjoints;

                            output1 >> numjoints;
                            for(int j=0;j<numjoints;j++){
                                getline (myfile,line);
                                getline (myfile,line);
                                int jointId=j+1;
                                double x;
                                double y;

                                std::istringstream output2(line);
                                output2 >> x;
                                output2 >> y;
                                std::pair<double, double> p;
                                p.first=x;
                                p.second=y;

                                newframe[jointId]=p;

                            }
                            frames.push_back(newframe);
                            //if(debug) qDebug("Deubg: '%s'\n", line.c_str());
                          }
                          myfile.close();
                      }
                  }
                  count++;
              }

          }
          closedir(pDIR);
          if(debug) qDebug("Number of Frames: '%d'\n", frames.size());
          this->data=frames;
      }

      else std::cout << "Unable to open file";

}

void DataSet::fetch(){
    std::string folder = "C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\BufferFolder\\";
    DIR *pDIR;
    struct dirent *entry;
    int count1=0;
    std::vector <std::map<int, std::pair<double,double> > >frames;
    if( pDIR=opendir(folder.c_str()) ){
        while(entry = readdir(pDIR)){
            if(count1>30){
                break;
            }
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    std::string line;
                    if(atoi(entry->d_name)>=count){
                        std::string files = folder+entry->d_name;
                        std::ifstream myfile;
                        if(debug) qDebug("Deubg: '%s'", files.c_str());
                        myfile.open(files.c_str());

                        std::map<int,std::pair<double,double> > newframe;
                        for(int j=0;j<20;j++){
                              getline (myfile,line);
                              int jointId=j+1;
                              double x;
                              double y;

                              std::istringstream output2(line);
                              output2 >> x;
                              output2 >> y;
                              std::pair<double, double> p;
                              p.first=x/100;
                              p.second=y/100;
                              newframe[jointId]=p;
                        }
                        frames.push_back(newframe);
                        myfile.close();
                        count++;
                        count1++;
                    }
            }

        }
        closedir(pDIR);
        if(debug) qDebug("Number of Frames: '%d'\n", frames.size());
        this->data=frames;
    }
}

void DataSet::clear(){
    std::string folder = "C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\BufferFolder\\";
    DIR *pDIR;
    struct dirent *entry;
    int count2=0;
    std::vector <std::map<int, std::pair<double,double> > >frames;
    if( pDIR=opendir(folder.c_str()) ){
        while(entry = readdir(pDIR)){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                if(atoi(entry->d_name)<count){
                    std::string files = folder+entry->d_name;
                    remove(files.c_str());
                    count2++;
                }
            }
        }

    }
    closedir(pDIR);
    this->data.clear();
    if(debug) qDebug("Number of Frames Deleted: '%d'\n", count2);
}
