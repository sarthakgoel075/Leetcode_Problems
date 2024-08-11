class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        int totalenergy=0;
        for(int i=0;i<energy.size();i++){
           totalenergy+=energy[i];
        }
        if(totalenergy>=initialEnergy){
            ans=totalenergy-initialEnergy+1;
        }
        cout<<ans;
        int reqexperience=0;
        for(int i=0;i<experience.size();i++){
          if(initialExperience<=experience[i]){
            reqexperience=reqexperience+(experience[i]-initialExperience+1);
            initialExperience=experience[i]+experience[i]+1;
          }
          else{
            initialExperience+=experience[i];
          }
        }
        ans+=reqexperience;
        return ans;
    }
};