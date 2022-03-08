#include <vector>

class Line{
    public:
        Line(){
            //I guess this one can initialize an empty vector
            x_vec.clear();
            y_vec.clear();
        }
        //Copy Constructor
        Line(Line const & ){
            auto xvec_it = x_vec.begin()
            auto yvec_it = y_vec.begin()

        }
        //Move Constructor
        Line(Line       &&);
        //Copy Assignment
        Line & operator=(Line const & );
        //Move Assignment
        Line & operator=(Line       &&);
        //Simple Allocation
        Line(size_t size);
        //Destructor
        ~Line();
        //Get current size 
        size_t size() const;
        float & x(size_t it) const;
        float & x(size_t it);
        float & y(size_t it) const;
        float & y(size_t it);

    private:
        //Lets keep an unitialized vector here
        std::vector<int> x_vec;
        std::vector<int> y_vec;

};

int main(int, char **)
{
    Line line(3);
    line.x(0) = 0; line.y(0) = 1;
    line.x(1) = 1; line.y(1) = 3;
    line.x(2) = 2; line.y(2) = 5;

    Line line2(line);
    line2.x(0) = 9;

    std::cout << "line: number of points = " << line.size() << std::endl;
    for (size_t it=0; it<line.size(); ++it)
    {
        std::cout << "point " << it << ":"
                  << " x = " << line.x(it)
                  << " y = " << line.y(it) << std::endl;
    }

    std::cout << "line2: number of points = " << line.size() << std::endl;
    for (size_t it=0; it<line.size(); ++it)
    {
        std::cout << "point " << it << ":"
                  << " x = " << line2.x(it)
                  << " y = " << line2.y(it) << std::endl;
    }

    return 0;
}
