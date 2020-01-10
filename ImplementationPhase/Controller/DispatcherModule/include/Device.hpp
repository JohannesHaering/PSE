class Device {
	private:
		std::string name;
		std::string type;
		long ram;
		double performance;
	public:
		Device();
		std::string getType();
		std::string getName();
		long getRAM();
		double getPerformance()
}
