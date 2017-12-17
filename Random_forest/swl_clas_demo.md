~~~
//main.cpp 
ClassificationDemo<F:AxisAlignedFeatureResponse>::Train(data, fFactory, trainParameter) (static型) 
{
  //用F， 类别数，特征Factory构造一个训练上下文类，该类包含两个形参类型的成员变量 
  ClassificationTrainingContext classificationContext(Data.countClass(), fFactory )
  //ForestTrainer.h中，算法入口 
  ForestTrainer<F, S:HistogramAggregator>::TrainForest(R, trainParameter, classificationContext, data, progress=0) 
  { 
    由于 progress=0，因此在这初始化一个用于打印中间过程
    progress ProgressStream defaultProgress(std::cout, parameters.Verbose)
		
    //建森林
    forest = auto_ptr<Forest<F,S>(new Forest<F,S>())

		//循环建树
		for  t <- 0 to trainParameter.NumerofTrees 
		{
		  defaultProgress[]<<”/r打印一下开始训练第几个树”
		
			tree = TreeTrainer<F, S>::TrainTree(R, classificationContext, trainParameter, data, progress)
			{
			  //开始训练树,首先定义一个训练类，把需要存放结果的向量都初始化为0，打印出来的算法9页
				TreeTrainingOperation<F,S> trainingOperation(R, classificationContext, trainParameter, data, progress)
			
				//Tree.h建立单个树，用向量vector<Node<F,S>>存树的节点，大小为2^(MaxDecisionLevels+1)-1,这里level=9
				tree_local = auto_ptr<Tree<F, S>>(new Tree<F, S>(trainParameter.MaxDecisionLevels))
        //递归深度优先训练二叉树的每一个节点（结果可能不是平衡二叉树）
        trainingOperation.TrainNodesRecurese(Tree:: vector<Node<F,S>> &nodes_: tree_local->GetNodes(), 0, 0, data.Count(), 0)
        //递归检查树节点的状态是否正确
        tree_local.CheckValid()
				retrun tree_local
       }
       //forest包含一个Tree指针类型的向量，AddTree将tree_local的指针填入forest中，并将tree_local指向空
			 forest->AddTree(tree_local)
    	}
   		defaultProgress[]<<”/r打印训练完毕”
   	 	return forest; //返回训练好的森林
    }
}
~~~
