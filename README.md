# Party2

Problem Description:

Tonight, people are coming to join a party held in the ADA city.
Since these people may have different backgrounds, such as coming from different countries, using different numbers of spaces to indent codes, placing the opening brackets of an if-statement at different locations, and so on, we can categorize them into N different types. During the party time, people chat with each other and persuade other people to become the same type as them.
To simplify the task, we assume that the party attendees form a line, and people join the party at either the front end or the back end of the line. Initially there is no attendee in the party, and then there are Q groups of people joining the party one by one. The i-th group contains ci people with the type ti (they all belong to the same type), and they join the party at the si end (where si is either “front” or “back”). When joining the party, they also persuade exactly ki people beside them to become the same type as them. That is, now, (ci + ki) people at the front (or the back) are all of the type ti.
Let Ci,j be the number of party attendees belonging the type j after the first i groups joined the party. Now, please find out the popularity for each of the N types. We define the popularity of type t as C1,t +C2,t +···+CQ,t.


Input:

The first line of the input contains two integers N and Q, indicating the number of types and the number of groups joining the party, respectively. There are then Q more lines in the input, the i-th line of which contains one string and three integers si, ci, ti, ki, indicating where the new group joined, the number of people in the new group, the type of the people in the group, and the number of attendees persuaded by the new group.


• 1 ≤ ti ≤ N ≤ Q ≤ 2 × 10^5
• si ∈ {“front”, “back”}
• 1≤ci ≤10^5
• 0≤ki ≤c1 +c2 +···+ci−1 ≤2×10^10


Output:

Output one line containing N space-separated integers. The i-th integer is the popularity of the type i.
