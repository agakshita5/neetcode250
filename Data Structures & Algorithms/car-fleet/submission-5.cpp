class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // compute (target-pos)/speed -> store it in stack until car behind[] >= car ahead
        // car behind time < st.top() means they belong to same fleet
        // car behind time >= st.top() means another fleet started
        // same ones group as one fleet, singles ones also one fleet.
        // at last st.size() is different number of fleets formed
        int n= position.size();

        stack<double> st; // storing new fleet's starting time

        vector<pair<int, double>> v; // pos, time
        for(int i=0;i<n;i++){
            v.push_back( {position[i], (double)(target-position[i])/speed[i]} );
        }
        // sorting in descending order based on pos
        sort(v.begin(), v.end(),
        [](auto& a, auto& b){ return a.first > b.first;}
        );

        st.push(v[0].second); // closest car time

        for(int i=1;i<n;i++){
            if(v[i].second > st.top()){
                st.push(v[i].second); 
            }
        }
        return st.size();
    }
};
