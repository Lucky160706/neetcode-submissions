class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cycle = 0;

        // Step 1: Count task frequencies
        int arr[26] = {0};

        for (char x : tasks) {
            arr[x - 'A']++;
        }

        // Step 2: Max Heap for available tasks
        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                pq.push(arr[i]);
            }
        }

        // Step 3: Cooldown queue
        // {remaining frequency, next available cycle}
        queue<pair<int, int>> cooldown;

        // Step 4: Simulate CPU cycles
        while (!pq.empty() || !cooldown.empty()) {
            cycle++;

            // Return tasks whose cooldown has expired
            if (!cooldown.empty() &&
                cooldown.front().second <= cycle) {

                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            // Execute the most frequent available task
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();

                freq--;

                // Put task into cooldown if it still has work
                if (freq > 0) {
                    cooldown.push({freq, cycle + n + 1});
                }
            }
            // Otherwise, CPU is idle
        }

        return cycle;
    }
};