class Game {
    private:
        int w, h, c;
        int** array;

        int GetNeighborhoodCount(int x, int y);
        void SetCell(int x, int y);
        void RemoveCell(int x, int y);
    public:
        void Init(int width, int height, int cellAmount);
        void ReInit();
        int GetCell(int x, int y);
        void Run();
};