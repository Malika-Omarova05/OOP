#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
#include <vector>

class GradeBook {
private:
    std::string studentName;  
    std::vector<int> grades;      

public:
    GradeBook(const std::string& name); 
    void addGrade(int grade);        
    void displayGrades() const;     
    double calculateAverage() const;   
};

#endif
