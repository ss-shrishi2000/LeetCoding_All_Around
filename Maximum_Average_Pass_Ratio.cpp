PROBLEM STATEMENT :-
  
  There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:
1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105
  
  SOLUTION :-
    
    struct CompareHeight {
    bool operator()(pair<long, long> &f, pair<long, long> &s){
            // a,b => a+1, b+1

            long a1 = f.first, b1 = f.second;
            long a2 = a1+1, b2 = b1+1;

            long u1 = s.first, v1 = s.second;
            long u2 = u1+1,  v2 = v1+1;

            long n1 = (a2*b1 - a1*b2), d1 = (b2*b1);
            long n2 = (u2*v1 - v2*u1), d2 = (v2*v1);

            return (d2*n1 - d1*n2) < 0;
        };
};
class Solution {
public:
    // pair<double, pair<int, int>> => change, coordinates
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue<pair<long, long> , vector<pair<long, long>>, CompareHeight> pq;
        int n = classes.size();

        for(int i = 0; i < n; i++)
        {
            long a = (long)classes[i][0];
            long b = (long)classes[i][1];
            pq.push({a, b});
        }

        int ex = extraStudents;
        while(ex--)
        {
            pair<long, long> p1 = pq.top();
            pq.pop();
            pq.push({p1.first + 1, p1.second + 1});
        }

        double ans = 0;
        while(pq.empty()==false)
        {
            pair<long, long> p1 = pq.top();
            double r = p1.first/(p1.second*1.0);
            ans += r;
            pq.pop();
        }
        ans = ans/(n*1.0);
        return ans;
    }
};
