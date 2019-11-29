using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GUI_Demo
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btn_topology_Click(object sender, RoutedEventArgs e)
        {
            var window = new Topology();
            window.Show();
        }

        private void btn_train_Click(object sender, RoutedEventArgs e)
        {
            var window = new Train();
            window.Show();
        }

        private void btn_classification_Click(object sender, RoutedEventArgs e)
        {
            var window = new ImageClassification();
            window.Show();
        }

        private void btn_detection_Click(object sender, RoutedEventArgs e)
        {
            var window = new Detection();
            window.Show();
        }
    }
}
