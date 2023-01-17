Side longerSide()
    {
        //throw std::logic_error("Waiting to be implemented");
        int left_count = 0;
        int right_count = 0;

        ChainLink* cur_ptr = this;
        while (NULL != cur_ptr->right)
        {
            cur_ptr = cur_ptr->right;
            right_count++;
        }

        ChainLink* cur_ptr = this;
        while (NULL != cur_ptr->left)
        {
            cur_ptr = cur_ptr->left;
            left_count++;
        }

        if (left_count > right_count)
        {
            return LEFT;
        }
        else
        {
            if (left_count < right_count)
            {
                return RIGHT;
            }
            else
            {
                return NONE;
            }
        }
    }