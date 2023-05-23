#include <iostream>
#include <vector>
using namespace std;

class Sort{
private:
    int findPos(vector<int>& nums,int left,int right){
        int val = nums[left];
        while(left < right){
            while(left < right){
                if(nums[right] < val){
                    nums[left] = nums[right];
                    break;
                }
                --right;
            }
            while(left < right){
                if(nums[left] > val){
                    nums[right] = nums[left];
                    break;
                }
                ++left;
            }
        }
        nums[left] = val;
        return left;
    }
    void mmerge(vector<int>& nums,int nums1begin,int nums1size,int nums2begin,int nums2size){/*传入有序数组*/
        if(nums2size > nums.size()){
            nums2size = nums.size();
        }
        if(nums1size > nums.size()){
            nums1size = nums.size();
        }
        int ii = nums1begin;
        int ji = nums2begin;
        vector<int> ans;
        for(int i = 0;i < nums1size + nums2size && ii < nums1size && ji < nums2size;++i){
            ans.push_back(min(nums[ii],nums[ji]));
            if(nums[ii] < nums[ji])
                ++ii;
            else ++ji;
        }
        for(;ii<nums1size;++ii){
            ans.push_back(nums[ii]);
        }
        for(;ji<nums2size;++ji){
            ans.push_back(nums[ji]);
        }
        int j = 0;
        for(int i = nums1begin;i < nums2size;++i,++j){
            nums[i] = ans[j];
        }
    }
public:


    void quickSort(vector<int>& nums,int left,int right){
        if(left < right){
            traverse(nums,nums.size());
            cout << "||||";
            int pos = findPos(nums,left,right);
            quickSort(nums,left,pos - 1);
            quickSort(nums,pos + 1,right);
        }
    }


    void mergeSort(vector<int>& nums){
        for(int i = 0;i < nums.size() - 1;i += 2){
            if(nums[i] > nums[i + 1] ){
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
        int ssize = 2;
        for(int i = 0;i < nums.size();++i){
            for(int j = 0;j < nums.size();j += ssize + ssize){
                mmerge(nums,j,j+ssize,j+ssize,j+ssize+ssize);
                traverse(nums,nums.size());
                cout << "||||";
                ssize *= 2;
            }

        }
    }

    void traverse(vector<int>& nums,int end){
        for(int i = 0;i < end;++i){
            cout <<  nums[i] << " ";
        }
    }
    int min(int a,int b){
        if(a < b)
            return a;
        return b;
    }
};
int main() {
    vector<int> nums = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};

    Sort * sort = new Sort();
    cout << "quickSort:" << endl;
    sort -> quickSort(nums,0,nums.size() - 1);
    cout << endl << "quickSort end." << endl;
    nums = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    cout << "mergeSort:" << endl;
    sort ->mergeSort(nums);
    sort ->traverse(nums, nums.size());
    return 0;
}
