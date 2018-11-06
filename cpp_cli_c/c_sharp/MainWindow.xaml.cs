using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
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

namespace ApplicationText
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private AlgClassWrapper wrapper = null;
        public MainWindow()
        {
            InitializeComponent();
            wrapper = new AlgClassWrapper(); //在C#工程bin\x64\Debug\下加入c++和CLI的两个.dll
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string value = this.m_TextBox.Text;
            int result = wrapper.run(Convert.ToInt32(value));
            MessageBox.Show("Result is " + result.ToString());
        }

        private void m_TextBox_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            Regex re = new Regex("[^0-9]");
            e.Handled = re.IsMatch(e.Text);
        }
    }
}
