#pragma once

namespace lab2Sim {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ dollarInitial;
	private: System::Windows::Forms::NumericUpDown^ euroInitial;

	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ brStartStop;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dollarInitial = (gcnew System::Windows::Forms::NumericUpDown());
			this->euroInitial = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->brStartStop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dollarInitial))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->euroInitial))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(366, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(261, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Начальная стоимость";
			// 
			// dollarInitial
			// 
			this->dollarInitial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->dollarInitial->AutoSize = true;
			this->dollarInitial->DecimalPlaces = 2;
			this->dollarInitial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dollarInitial->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->dollarInitial->Location = System::Drawing::Point(371, 70);
			this->dollarInitial->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->dollarInitial->Name = L"dollarInitial";
			this->dollarInitial->Size = System::Drawing::Size(120, 34);
			this->dollarInitial->TabIndex = 1;
			this->dollarInitial->ValueChanged += gcnew System::EventHandler(this, &MyForm::dollarInitial_ValueChanged);
			// 
			// euroInitial
			// 
			this->euroInitial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->euroInitial->AutoSize = true;
			this->euroInitial->DecimalPlaces = 2;
			this->euroInitial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->euroInitial->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->euroInitial->Location = System::Drawing::Point(520, 70);
			this->euroInitial->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->euroInitial->Name = L"euroInitial";
			this->euroInitial->Size = System::Drawing::Size(120, 34);
			this->euroInitial->TabIndex = 2;
			this->euroInitial->ValueChanged += gcnew System::EventHandler(this, &MyForm::euroInitial_ValueChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(418, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"$";
			// 
			// label
			// 
			this->label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->Location = System::Drawing::Point(567, 38);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(26, 29);
			this->label->TabIndex = 4;
			this->label->Text = L"€";
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->LabelStyle->Interval = 0;
			chartArea1->AxisY->LabelStyle->Interval = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(-6, 137);
			this->chart1->MaximumSize = System::Drawing::Size(4000, 4000);
			this->chart1->MinimumSize = System::Drawing::Size(500, 500);
			this->chart1->Name = L"chart1";
			this->chart1->Padding = System::Windows::Forms::Padding(1);
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series1->LabelFormat = L"f2";
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::Transparent;
			series1->Name = L"Dollar";
			series1->SmartLabelStyle->MaxMovingDistance = 300;
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series2->LabelFormat = L"f2";
			series2->Legend = L"Legend1";
			series2->Name = L"Euro";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1047, 535);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// brStartStop
			// 
			this->brStartStop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->brStartStop->AutoSize = true;
			this->brStartStop->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->brStartStop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->brStartStop->Location = System::Drawing::Point(678, 47);
			this->brStartStop->Name = L"brStartStop";
			this->brStartStop->Size = System::Drawing::Size(129, 39);
			this->brStartStop->TabIndex = 6;
			this->brStartStop->Text = L"Start/Stop";
			this->brStartStop->UseVisualStyleBackColor = true;
			this->brStartStop->Click += gcnew System::EventHandler(this, &MyForm::brStartStop_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 672);
			this->Controls->Add(this->brStartStop);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->euroInitial);
			this->Controls->Add(this->dollarInitial);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dollarInitial))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->euroInitial))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		const double k = 0.02;
		Random^ rnd = gcnew Random();
		int i = 0;
		double dollar;
		double euro;

	private: System::Void brStartStop_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!timer1->Enabled) {
			timer1->Start();
		}
		else timer1->Stop();
}
		   double NormalSample() {
			   double u1 = rnd->NextDouble();
			   double u2 = rnd->NextDouble();
			   return Math::Sqrt(-2.0 * Math::Log(u1)) * Math::Cos(2 * Math::PI * u2);
		   }

				
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	double dt = 1.0;
	double mu = 0.01;       // Средний рост
	double sigma = 0.05;    // Волатильность

	double z1 = NormalSample(); // Случайное число из нормального распределения
	double z2 = NormalSample(); // Для евро

	dollar *= Math::Exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math::Sqrt(dt) * z1);
	euro *= Math::Exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math::Sqrt(dt) * z2);

	chart1->Series[0]->Points->AddXY(i, dollar);
	chart1->Series[1]->Points->AddXY(i, euro);
	++i;
}

private: System::Void dollarInitial_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	dollar = (double)dollarInitial->Value;
}
private: System::Void euroInitial_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	euro = (double)euroInitial->Value;
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
